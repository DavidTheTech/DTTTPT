#include <cmath>
#include "PreviewModel.h"
#include "client/Client.h"
#include "client/GameSave.h"
#include "gui/dialogues/ErrorMessage.h"
#include "PreviewModelException.h"

PreviewModel::PreviewModel():
	doOpen(false),
	canOpen(true),
	save(NULL),
	saveData(NULL),
	saveComments(NULL),
	commentBoxEnabled(false),
	commentsLoaded(false),
	commentsTotal(0),
	commentsPageNumber(1)
{

}

void PreviewModel::SetFavourite(bool favourite)
{
	if(save)
	{
		if (Client::Ref().FavouriteSave(save->id, favourite) == RequestOkay)
			save->Favourite = favourite;
		else if (favourite)
			throw PreviewModelException("Error, could not fav. the save: " + Client::Ref().GetLastError());
		else
			throw PreviewModelException("Error, could not unfav. the save: " + Client::Ref().GetLastError());
		notifySaveChanged();
	}
}

bool PreviewModel::GetCommentBoxEnabled()
{
	return commentBoxEnabled;
}

void PreviewModel::SetCommentBoxEnabled(bool enabledState)
{
	if(enabledState != commentBoxEnabled)
	{
		commentBoxEnabled = enabledState;
		notifyCommentBoxEnabledChanged();
	}
}

void PreviewModel::UpdateSave(int saveID, int saveDate)
{
	this->tSaveID = saveID;
	this->tSaveDate = saveDate;

	if (save)
	{
		delete save;
		save = NULL;
	}
	if (saveData)
	{
		delete saveData;
		saveData = NULL;
	}
	if (saveComments)
	{
		for (size_t i = 0; i < saveComments->size(); i++)
			delete saveComments->at(i);
		saveComments->clear();
		delete saveComments;
		saveComments = NULL;
	}
	notifySaveChanged();
	notifySaveCommentsChanged();

	RequestBroker::Ref().Start(Client::Ref().GetSaveDataAsync(saveID, saveDate), this, 1);
	RequestBroker::Ref().Start(Client::Ref().GetSaveAsync(saveID, saveDate), this, 2);

	if (!GetDoOpen())
	{
		commentsLoaded = false;
		RequestBroker::Ref().Start(Client::Ref().GetCommentsAsync(saveID, (commentsPageNumber-1)*20, 20), this, 3);
	}
}

void PreviewModel::SetDoOpen(bool doOpen)
{
	this->doOpen = doOpen;
}

bool PreviewModel::GetDoOpen()
{
	return doOpen;
}

bool PreviewModel::GetCanOpen()
{
	return canOpen;
}

SaveInfo * PreviewModel::GetSave()
{
	return save;
}

int PreviewModel::GetCommentsPageNum()
{
	return commentsPageNumber;
}

int PreviewModel::GetCommentsPageCount()
{
	return max(1, (int)(ceil(commentsTotal/20.0f)));
}

bool PreviewModel::GetCommentsLoaded()
{
	return commentsLoaded;
}

void PreviewModel::UpdateComments(int pageNumber)
{
	if (commentsLoaded)
	{
		commentsLoaded = false;
		if (saveComments)
		{
			for (size_t i = 0; i < saveComments->size(); i++)
				delete saveComments->at(i);
			saveComments->clear();
			delete saveComments;
			saveComments = NULL;
		}

		commentsPageNumber = pageNumber;
		if (!GetDoOpen())
			RequestBroker::Ref().Start(Client::Ref().GetCommentsAsync(tSaveID, (commentsPageNumber-1)*20, 20), this, 3);

		notifySaveCommentsChanged();
		notifyCommentsPageChanged();
	}
}

void PreviewModel::CommentAdded()
{
	if (save)
		save->Comments++;
	commentsTotal++;
}

void PreviewModel::OnResponseReady(void * object, int identifier)
{
	if (identifier == 1)
	{
		delete saveData;
		saveData = (std::vector<unsigned char>*)object;
	}
	if (identifier == 2)
	{
		delete save;
		save = (SaveInfo*)object;
	}
	if (identifier == 3)
	{
		if (saveComments)
		{
			for (size_t i = 0; i < saveComments->size(); i++)
				delete saveComments->at(i);
			saveComments->clear();
			delete saveComments;
			saveComments = NULL;
		}
		saveComments = (std::vector<SaveComment*>*)object;
		commentsLoaded = true;
		notifySaveCommentsChanged();
		notifyCommentsPageChanged();
	}

	if (identifier == 1 || identifier == 2)
	{
		if (save && saveData)
		{
			commentsTotal = save->Comments;
			try
			{
				GameSave *gameSave = new GameSave(*saveData);
				if (gameSave->fromNewerVersion)
					new ErrorMessage("This save is from a newer version", "Please update TPT in game or at http://powdertoy.co.uk");
				save->SetGameSave(gameSave);
			}
			catch(ParseException &e)
			{
				new ErrorMessage("Error", e.what());
				canOpen = false;
			}
			notifySaveChanged();
			notifyCommentsPageChanged();
			//make sure author name comments are red
			if (commentsLoaded)
				notifySaveCommentsChanged();
		}
	}
}

void PreviewModel::OnResponseFailed(int identifier)
{
	if (identifier == 3)
	{
		if (saveComments)
		{
			for (size_t i = 0; i < saveComments->size(); i++)
				delete saveComments->at(i);
			saveComments->clear();
			delete saveComments;
			saveComments = NULL;
		}
		saveComments = NULL;
		commentsLoaded = true;
		notifySaveCommentsChanged();
	}
	else
	{
		for (size_t i = 0; i < observers.size(); i++)
		{
			observers[i]->SaveLoadingError(Client::Ref().GetLastError());
		}
	}
}

void PreviewModel::Update()
{

}

std::vector<SaveComment*> * PreviewModel::GetComments()
{
	return saveComments;
}

void PreviewModel::notifySaveChanged()
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->NotifySaveChanged(this);
	}
}

void PreviewModel::notifyCommentBoxEnabledChanged()
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->NotifyCommentBoxEnabledChanged(this);
	}
}

void PreviewModel::notifyCommentsPageChanged()
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->NotifyCommentsPageChanged(this);
	}
}

void PreviewModel::notifySaveCommentsChanged()
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->NotifyCommentsChanged(this);
	}
}

void PreviewModel::AddObserver(PreviewView * observer)
{
	observers.push_back(observer);
	observer->NotifySaveChanged(this);
	observer->NotifyCommentsChanged(this);
	observer->NotifyCommentsPageChanged(this);
	observer->NotifyCommentBoxEnabledChanged(this);
}


PreviewModel::~PreviewModel()
{
	RequestBroker::Ref().DetachRequestListener(this);
	delete save;
	delete saveData;
	if (saveComments)
	{
		for (size_t i = 0; i < saveComments->size(); i++)
			delete saveComments->at(i);
		saveComments->clear();
		delete saveComments;
	}
}

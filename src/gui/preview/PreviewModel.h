#ifndef PREVIEWMODEL_H
#define PREVIEWMODEL_H

#include <vector>
#include <iostream>
#include "common/tpt-thread.h"
#include "PreviewView.h"
#include "client/SaveInfo.h"
#include "gui/preview/Comment.h"
#include "gui/search/Thumbnail.h"
#include "client/requestbroker/RequestListener.h"

using namespace std;

class PreviewView;
class PreviewModel: RequestListener {
	bool doOpen;
	bool canOpen;
	vector<PreviewView*> observers;
	SaveInfo * save;
	std::vector<unsigned char> * saveData;
	std::vector<SaveComment*> * saveComments;
	void notifySaveChanged();
	void notifySaveCommentsChanged();
	void notifyCommentsPageChanged();
	void notifyCommentBoxEnabledChanged();

	//Background retrieval
	int tSaveID;
	int tSaveDate;

	//
	bool commentBoxEnabled;
	bool commentsLoaded;
	int commentsTotal;
	int commentsPageNumber;

public:
	PreviewModel();
	SaveInfo * GetSave();
	std::vector<SaveComment*> * GetComments();

	bool GetCommentBoxEnabled();
	void SetCommentBoxEnabled(bool enabledState);

	bool GetCommentsLoaded();
	int GetCommentsPageNum();
	int GetCommentsPageCount();
	void UpdateComments(int pageNumber);
	void CommentAdded();

	void AddObserver(PreviewView * observer);
	void UpdateSave(int saveID, int saveDate);
	void SetFavourite(bool favourite);
	bool GetDoOpen();
	bool GetCanOpen();
	void SetDoOpen(bool doOpen);
	void Update();
	virtual void OnResponseReady(void * object, int identifier);
	virtual void OnResponseFailed(int identifier);
	virtual ~PreviewModel();
};

#endif /* PREVIEWMODEL_H */

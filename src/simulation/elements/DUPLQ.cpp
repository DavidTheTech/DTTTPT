#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_DUPLQ PT_DUPLQ 184
Element_DUPLQ::Element_DUPLQ()
{
	Identifier = "DEFAULT_PT_DUPLQ";
	Name = "DUPLQ";
	Colour = PIXPACK(0x0066FF);
	MenuVisible = 1;
	MenuSection = SC_DTT;
	Enabled = 1;

	Advection = 0.6f;
	AirDrag = 0.01f * CFDS;
	AirLoss = 0.98f;
	Loss = 0.95f;
	Collision = 0.0f;
	Gravity = 0.1f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 2;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 20;

	Weight = 30;

	Temperature = R_TEMP-2.0f	+273.15f;
	HeatConduct = 20;
	Description = "Self Replicating Liquid (Use SOAP To Stop Duplicating).";

	//Properties = TYPE_LIQUID|PROP_CONDUCTS|PROP_LIFE_DEC|PROP_NEUTPASS;
	Properties = TYPE_LIQUID|PROP_LIFE_DEC|PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 273.15f;
	LowTemperatureTransition = NT;
	HighTemperature = 373.0f;
	HighTemperatureTransition = NT;

	Update = &Element_DUPLQ::update;
}

//#TPT-Directive ElementHeader Element_DUPLQ static int update(UPDATE_FUNC_ARGS)
int Element_DUPLQ::update(UPDATE_FUNC_ARGS)
{
	//if (parts[i].temp>303&&parts[i].temp<317) {
	//if (parts[i].temp>303) {
	int r, rx, ry, rndstore = rand();
	for (rx=-1; rx<2; rx++)
	{
		for (ry=-1; ry<2; ry++)
		{
			if (BOUNDS_CHECK && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if (!r)
					continue;

				//spread "being cured" state
				if (parts[r>>8].pavg[0] && ((r&0xFF) == PT_DUPLQ))
				{
					parts[i].pavg[0] = parts[r>>8].pavg[0] + ((rndstore & 0x3) ? 2:1);
					return 0;
				}
				//soap cures virus
				else if ((r&0xFF) == PT_SOAP)
				{
					parts[i].pavg[0] += 10;
					if (!(rndstore & 0x3))
						sim->kill_part(r>>8);
					return 0;
				}
			}
		}
	}
	if (3>(rand()%20))
	{
		sim->create_part(-1, x+rand()%3-1, y+rand()%3-1, PT_DUPLQ);
	}
	//}
	return 0;
}

Element_DUPLQ::~Element_DUPLQ() {}

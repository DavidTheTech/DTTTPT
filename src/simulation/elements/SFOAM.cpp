#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_SFOAM PT_SFOAM 183
Element_SFOAM::Element_SFOAM()
{
	Identifier = "DEFAULT_PT_SFOAM";
	Name = "SFOAM";
	Colour = PIXPACK(0xFFD480);
	MenuVisible = 1;
	MenuSection = SC_DTT;
	Enabled = 1;

	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.90f;
	Loss = 0.00f;
	Collision = 0.0f;
	Gravity = 0.0f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 0;

	Flammable = 0;
	Explosive = 0;
	Meltable = 5;
	Hardness = 1;

	Weight = 75;

	Temperature = R_TEMP+0.0f	+273.15f;
	HeatConduct = 110;
	Description = "Solid Foam, Expands at (~37C).";

	Properties = TYPE_SOLID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1173.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &Element_SFOAM::update;
}

//#TPT-Directive ElementHeader Element_SFOAM static int update(UPDATE_FUNC_ARGS)
int Element_SFOAM::update(UPDATE_FUNC_ARGS)
{
	//if (parts[i].temp>303&&parts[i].temp<317) {
	if (3>(rand()%20))
	{
		if (parts[i].temp>303) {
			sim->create_part(-1, x+rand()%3-1, y+rand()%3-1, PT_SFOAM);
		}
	}
	return 0;
}

Element_SFOAM::~Element_SFOAM() {}

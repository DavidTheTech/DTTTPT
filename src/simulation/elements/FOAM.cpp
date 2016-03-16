#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_FOAM PT_FOAM 180
Element_FOAM::Element_FOAM()
{
	Identifier = "DEFAULT_PT_FOAM";
	Name = "FOAM";
	Colour = PIXPACK(0xFFD480);
	MenuVisible = 1;
	MenuSection = SC_DTT;
	Enabled = 1;

	Advection = 0.4f;
	AirDrag = 0.04f * CFDS;
	AirLoss = 0.94f;
	Loss = 0.95f;
	Collision = -0.1f;
	Gravity = 0.3f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 1;

	Flammable = 0;
	Explosive = 0;
	Meltable = 5;
	Hardness = 1;

	Weight = 75;

	Temperature = R_TEMP+0.0f	+273.15f;
	HeatConduct = 110;
	Description = "Foam, Expands at (~37C).";

	Properties = TYPE_PART;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1173.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &Element_FOAM::update;;
}

//#TPT-Directive ElementHeader Element_FOAM static int update(UPDATE_FUNC_ARGS)
int Element_FOAM::update(UPDATE_FUNC_ARGS)
{
	//if (parts[i].temp>303&&parts[i].temp<317) {
	if (3>(rand()%20))
	{
		if (parts[i].temp>303) {
			sim->create_part(-1, x+rand()%3-1, y+rand()%3-1, PT_FOAM);
		}
	}
	return 0;
}

Element_FOAM::~Element_FOAM() {}

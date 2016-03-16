#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_COLNT PT_COLNT 181
Element_COLNT::Element_COLNT()
{
	Identifier = "DEFAULT_PT_COLNT";
	Name = "CLNT";
	Colour = PIXPACK(0x000099);
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
	Description = "Coolant. Takes heat from anything useful for Electronics that use water";

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

	Update = &Element_COLNT::update;
}

//#TPT-Directive ElementHeader Element_COLNT static int update(UPDATE_FUNC_ARGS)
int Element_COLNT::update(UPDATE_FUNC_ARGS)
{
	//if (parts[i].temp>313) {
		parts[i].temp = 0;
	//}
	return 0;
}

Element_COLNT::~Element_COLNT() {}

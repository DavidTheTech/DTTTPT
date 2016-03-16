#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_SHLNT PT_SHLNT 187
Element_SHLNT::Element_SHLNT()
{
	Identifier = "DEFAULT_PT_SHLNT";
	Name = "SHLNT";
	Colour = PIXPACK(0xCC0000);
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
	Meltable = 0;
	Hardness = 20;

	Weight = 100;

	Temperature = R_TEMP-2.0f	+273.15f;
	HeatConduct = 20;
	Description = "Solid Heatant. Generates Heat";

	//Properties = TYPE_LIQUID|PROP_CONDUCTS|PROP_LIFE_DEC|PROP_NEUTPASS;
	Properties = TYPE_SOLID|PROP_LIFE_DEC|PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 273.15f;
	LowTemperatureTransition = NT;
	HighTemperature = NT;
	HighTemperatureTransition = NT;

	Update = &Element_SHLNT::update;
}

//#TPT-Directive ElementHeader Element_SHLNT static int update(UPDATE_FUNC_ARGS)
int Element_SHLNT::update(UPDATE_FUNC_ARGS)
{
	//if (parts[i].temp>313) {
	parts[i].temp = 1273;
	//}
	return 0;
}

Element_SHLNT::~Element_SHLNT() {}

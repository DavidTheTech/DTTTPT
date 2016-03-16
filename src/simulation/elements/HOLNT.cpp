#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_HOLNT PT_HOLNT 188
Element_HOLNT::Element_HOLNT()
{
	Identifier = "DEFAULT_PT_HOLNT";
	Name = "HOLNT";
	Colour = PIXPACK(0xCC0000);
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
	Description = "Heatant. Generates Heat";

	//Properties = TYPE_LIQUID|PROP_CONDUCTS|PROP_LIFE_DEC|PROP_NEUTPASS;
	Properties = TYPE_LIQUID|PROP_LIFE_DEC|PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 273.15f;
	LowTemperatureTransition = NT;
	HighTemperature = NT;
	HighTemperatureTransition = NT;

	Update = &Element_HOLNT::update;
}

//#TPT-Directive ElementHeader Element_HOLNT static int update(UPDATE_FUNC_ARGS)
int Element_HOLNT::update(UPDATE_FUNC_ARGS)
{
	//if (parts[i].temp>313) {
	parts[i].temp = 1273;
	//}
	return 0;
}

Element_HOLNT::~Element_HOLNT() {}

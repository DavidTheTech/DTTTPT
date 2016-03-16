#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_SCLNT PT_SCLNT 182
Element_SCLNT::Element_SCLNT()
{
	Identifier = "DEFAULT_PT_SCLNT";
	Name = "SCLNT";
	Colour = PIXPACK(0x000099);
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
	Description = "Solid Coolant. Takes heat from anything useful for Electronics that use water";

	//Properties = TYPE_LIQUID|PROP_CONDUCTS|PROP_LIFE_DEC|PROP_NEUTPASS;
	Properties = TYPE_SOLID|PROP_LIFE_DEC|PROP_NEUTPASS;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = 273.15f;
	LowTemperatureTransition = NT;
	HighTemperature = 373.0f;
	HighTemperatureTransition = NT;

	Update = &Element_SCLNT::update;
}

//#TPT-Directive ElementHeader Element_SCLNT static int update(UPDATE_FUNC_ARGS)
int Element_SCLNT::update(UPDATE_FUNC_ARGS)
{
	//if (parts[i].temp>313) {
		parts[i].temp = 0;
	//}
	return 0;
}

Element_SCLNT::~Element_SCLNT() {}

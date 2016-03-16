#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_ALUM PT_ALUM 191
Element_ALUM::Element_ALUM()
{
	Identifier = "DEFAULT_PT_ALUM";
	Name = "ALUM";
	Colour = PIXPACK(0xBCC6CC);
	MenuVisible = 1;
	MenuSection = SC_DTTB;
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
	Meltable = 1;
	Hardness = 1;

	Weight = 100;

	Temperature = R_TEMP+0.0f	+273.15f;
	HeatConduct = 251;
	Description = "Aluminum suggested by Solace";

	Properties = TYPE_SOLID|PROP_CONDUCTS|PROP_LIFE_DEC|PROP_HOT_GLOW;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 933.45f;
	HighTemperatureTransition = PT_LAVA;

	Update = NULL;
}

Element_ALUM::~Element_ALUM() {}

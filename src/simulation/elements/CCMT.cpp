#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_CCMT PT_CCMT 196
Element_CCMT::Element_CCMT()
{
	Identifier = "DEFAULT_PT_CCMT";
	Name = "CCMT";
	Colour = PIXPACK(0xA0A0A0);
	MenuVisible = 1;
	MenuSection = SC_DTTB;
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

	Weight = 90;

	Temperature = R_TEMP+0.0f	+273.15f;
	HeatConduct = 150;
	Description = "Cracked Cement.";

	Properties = TYPE_PART;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 983.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = NULL;
}

Element_CCMT::~Element_CCMT() {}

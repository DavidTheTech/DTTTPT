#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_WCMT PT_WCMT 193
Element_WCMT::Element_WCMT()
{
	Identifier = "DEFAULT_PT_WCMT";
	Name = "WCMT";
	Colour = PIXPACK(0x6D6968);
	MenuVisible = 1;
	MenuSection = SC_DTTB;
	Enabled = 1;

	Advection = 0.3f;
	AirDrag = 0.02f * CFDS;
	AirLoss = 0.95f;
	Loss = 0.80f;
	Collision = 0.0f;
	Gravity = 0.15f;
	Diffusion = 0.00f;
	HotAir = 0.000001f* CFDS;
	Falldown = 2;

	Flammable = 5;
	Explosive = 0;
	Meltable = 0;
	Hardness = 2;

	Weight = 25;

	Temperature = R_TEMP+28.0f+273.15f;
	HeatConduct = 44;
	Description = "Wet Cement suggested by Solace Sets at 400c.";

	Properties = TYPE_LIQUID;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = NT;
	LowTemperatureTransition = NT;
	HighTemperature = 673.15f;
	HighTemperatureTransition = PT_DCMT;

	Update = NULL;
}

Element_WCMT::~Element_WCMT() {}

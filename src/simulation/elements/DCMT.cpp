#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_DCMT PT_DCMT 194
Element_DCMT::Element_DCMT()
{
	Identifier = "DEFAULT_PT_DCMT";
	Name = "DCMT";
	Colour = PIXPACK(0xB6B6B4);
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
	Meltable = 0;
	Hardness = 1;

	Weight = 100;

	Temperature = R_TEMP+0.0f	+273.15f;
	HeatConduct = 251;
	Description = "Dry Cement suggested by Solace.";

	Properties = TYPE_SOLID|PROP_HOT_GLOW;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = 40.0f;
	HighPressureTransition = PT_CCMT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1223.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = NULL;
	Graphics = &Element_DCMT::graphics;
}

//#TPT-Directive ElementHeader Element_DCMT static int graphics(GRAPHICS_FUNC_ARGS)
int Element_DCMT::graphics(GRAPHICS_FUNC_ARGS)
{
	if (cpart->tmp == 1)
	{
		*pixel_mode |= FIRE_ADD;
		*colb += 100;

		*firea = 40;
		*firer = *colr;
		*fireg = *colg;
		*fireb = *colb;
	}
	return 0;  
}

Element_DCMT::~Element_DCMT() {}

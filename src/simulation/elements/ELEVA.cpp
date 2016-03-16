#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_ELEVA PT_ELEVA 189
Element_ELEVA::Element_ELEVA()
{
	Identifier = "DEFAULT_PT_ELEVA";
	Name = "ELEVA";
	Colour = PIXPACK(0x808080);
	MenuVisible = 1;
	MenuSection = SC_DTT;
	Enabled = 1;

	Advection = 0.0f;
	AirDrag = 0.00f * CFDS;
	AirLoss = 0.90f;
	Loss = 0.00f;
	Collision = 0.0f;
	Gravity = 0.1f;
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
	Description = "Elevator See The Mod Forum Post On How To Use.";

	Properties = TYPE_PART|TYPE_SOLID|PROP_HOT_GLOW;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = 8.8f;
	HighPressureTransition = PT_STNE;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1223.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = NULL;
	Graphics = &Element_ELEVA::graphics;
}

//#TPT-Directive ElementHeader Element_ELEVA static int graphics(GRAPHICS_FUNC_ARGS)
int Element_ELEVA::graphics(GRAPHICS_FUNC_ARGS)
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

Element_ELEVA::~Element_ELEVA() {}

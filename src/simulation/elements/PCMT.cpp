#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_PCMT PT_PCMT 195
Element_PCMT::Element_PCMT()
{
	Identifier = "DEFAULT_PT_PCMT";
	Name = "PCMT";
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
	Description = "Cement Powder Mix With Water.";

	Properties = TYPE_PART;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 983.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &Element_PCMT::update;
}

//#TPT-Directive ElementHeader Element_PCMT static int update(UPDATE_FUNC_ARGS)
int Element_PCMT::update(UPDATE_FUNC_ARGS)
{
	int r, rx, ry;
	for (rx=-1; rx<2; rx++)
		for (ry=-1; ry<2; ry++)
			if (BOUNDS_CHECK && (rx || ry))
			{
				r = pmap[y+ry][x+rx];
				if (!r)
					continue;
				if ((r&0xFF)==PT_WATR && !(rand()%50))
				{
					sim->part_change_type(i,x,y,PT_WCMT);
				}
			}
	return 0;
}

Element_PCMT::~Element_PCMT() {}

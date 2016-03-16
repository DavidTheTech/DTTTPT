#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_MGNM PT_MGNM 192
Element_MGNM::Element_MGNM()
{
	Identifier = "DEFAULT_PT_MGNM";
	Name = "MGNM";
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
	Description = "Magnesium suggested by Solace.";

	Properties = TYPE_SOLID|PROP_CONDUCTS|PROP_LIFE_DEC|PROP_HOT_GLOW;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 923.15f;
	HighTemperatureTransition = PT_LAVA;

	Update = NULL;
}

Element_MGNM::~Element_MGNM() {}

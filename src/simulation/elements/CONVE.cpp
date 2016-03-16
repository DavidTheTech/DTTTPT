#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_CONVE PT_CONVE 190
Element_CONVE::Element_CONVE()
{
	Identifier = "DEFAULT_PT_CONVE";
	Name = "CONVE";
	Colour = PIXPACK(0x404060);
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
	Meltable = 1;
	Hardness = 1;

	Weight = 100;

	Temperature = R_TEMP+0.0f	+273.15f;
	HeatConduct = 251;
	Description = "Conveyor Moves Particles To The Right (WIP)";

	Properties = TYPE_SOLID|PROP_LIFE_DEC|PROP_HOT_GLOW;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1273.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &Element_CONVE::update;
}

//#TPT-Directive ElementHeader Element_CONVE static int update(UPDATE_FUNC_ARGS)
int Element_CONVE::update(UPDATE_FUNC_ARGS)
{
	int r, rx, ry, trade;
	for (rx=-2; rx<3; rx++)
	{
		for (ry=-2; ry<3; ry++)
		{
			if (BOUNDS_CHECK && (rx || ry))
			{
				parts[r>>8].vx = (((parts[i].x)-(parts[r>>8].x))/10)*(rand()%5+10/10);
			}
		}
	}
	/*if(1>rand()%80){
	for (rx=-24; rx<24; rx++)
		for (ry=-24; ry<24; ry++)
		if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry)){
				r = pmap[y+ry][x+rx];
				if ((r>>8)>=NPART || !r)
					continue;
				if ((r&0xFF)==PT_BRMT){
					if ((parts[r>>8].ctype != PT_BRMT)||(parts[i].y<parts[r>>8].y)){
						parts[r>>8].vx = (((parts[i].x)-(parts[r>>8].x))/10)*(rand()%5+10/10);
						parts[r>>8].vy = (((parts[i].y)-(parts[r>>8].y))/10)*(rand()%5+10/10);
					}else{
						parts[r>>8].vx = (((parts[i].x)-(parts[r>>8].x))/140)*(rand()%5+10/10);
						parts[r>>8].vy = (((parts[i].y)-(parts[r>>8].y))/140)*(rand()%5+10/10);
					}
				}
		}
	}*/
	
	return 0;
}

Element_CONVE::~Element_CONVE() {}

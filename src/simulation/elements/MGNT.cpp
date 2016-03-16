#include "simulation/Elements.h"
//#TPT-Directive ElementClass Element_MGNT PT_MGNT 185
Element_MGNT::Element_MGNT()
{
	Identifier = "DEFAULT_PT_MGNT";
	Name = "MGNT";
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
	Description = "An attempt at a magnet (Use BRMT)";

	Properties = TYPE_SOLID|PROP_LIFE_DEC|PROP_HOT_GLOW;

	LowPressure = IPL;
	LowPressureTransition = NT;
	HighPressure = IPH;
	HighPressureTransition = NT;
	LowTemperature = ITL;
	LowTemperatureTransition = NT;
	HighTemperature = 1273.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &Element_MGNT::update;
}

//#TPT-Directive ElementHeader Element_MGNT static int update(UPDATE_FUNC_ARGS)
int Element_MGNT::update(UPDATE_FUNC_ARGS)
{
	int r, rx, ry;
	for (rx=-1; rx<2; rx++)
		for (ry=-1; ry<2; ry++)
			if (x+rx>=0 && y+ry>0 && x+rx<XRES && y+ry<YRES && (rx || ry)){
				r = pmap[y+ry][x+rx];
				if ((r>>8)>=NPART || !r)
					continue;
				if ((((r&0xFF) == PT_SALT && 15>(rand()/(RAND_MAX/700)))||((r&0xFF) == PT_SLTW && 30>(rand()/(RAND_MAX/2000)))||((r&0xFF) == PT_WATR && 5 >(rand()/(RAND_MAX/6000)))||((r&0xFF) == PT_O2 && 2 >(rand()/(RAND_MAX/500)))||((r&0xFF) == PT_LO2))&&(!(parts[i].life))){
					sim->part_change_type(i,x,y,PT_BMTL);
					parts[i].tmp=(rand()/(RAND_MAX/10))+20;
				}
				if((r&0xFF)==PT_BRMT){
					parts[r>>8].vx = 0;
					parts[r>>8].vy = 0;
					parts[r>>8].ctype = PT_BRMT;
				}
			}
	if(1>rand()%80){
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
	}
	
	return 0;
}

Element_MGNT::~Element_MGNT() {}

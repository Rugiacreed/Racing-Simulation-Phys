#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include  "PhysVehicle3D.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();
	mat4x4 m;
	App->player->vehicle->GetTransform(&m);
	vec3 positionplayer = { m[12],m[13],m[14] };
	LOG("%f,%f,%f", positionplayer.x, positionplayer.y, positionplayer.z);
	if ((positionplayer.x <= -110) && (positionplayer.x >= -160) && (positionplayer.y <= 38) && (positionplayer.y >= 0) && (positionplayer.z <= -148) && (positionplayer.z >= -168)) {
		winner = true;
	}
	else;

						//"race" map
	//no exit line(backwards)
	CreateCube(0, { 0,1,0 }, { 0, 0, -9.5 }, { 14, 5, 1}, White);
	//start zone
	CreateCube(0, { 0,1,0 }, { 0, 0, 0}, { 14, 0.1, 10 }, Red);
	CreateCube(0, { 0,1,0 }, { 7, 0, 50}, {1, 3, 120}, White);
	CreateCube(0, { 0,1,0 }, { -7, 0, 50}, { 1, 3, 120}, White);
	CreateCube(0, { 0,1,0 }, { 0, 0, 110 }, { 14, 0.1, 10 }, Red);
	CreateCube(-10, { 1,0,0 }, { 0, 0.1, 115.8 }, { 14, 0.1, 2 }, Red);
	CreateCube(-15, { 1,0,0 }, { 0, 0.5, 117.7 }, { 14, 0.1, 2 }, Red);
	CreateCube(-25, { 1,0,0 }, { 0, 1.1, 119.5 }, { 14, 0.1, 2 }, Red);
	CreateCube(-30, { 1,0,0 }, { 0, 2., 121.2 }, { 14, 0.1, 2 }, Red);
	
	//jump ramp
	CreateCube(0, { 0,1,0 }, { 0, 5, 200 }, { 18, 2, 60 }, Red);
	CreateCube(0, { 0,1,0 }, { 9, 7, 195 }, { 1, 9, 55 }, Red);
	CreateCube(0, { 0,1,0 }, { -9, 7, 200 }, { 1, 9, 60 }, Red);
	CreateCube(15, { 0,1,0 }, { 0, 5, 230 }, { 18, 2, 10 }, Red);
	CreateCube(25, { 0,1,0 }, { 3, 5, 235 }, { 18, 2, 10 }, Red);
	CreateCube(35, { 0,1,0 }, { 6, 5, 237 }, { 18, 2, 10 }, Red);
	CreateCube(50, { 0,1,0 }, { 11, 5, 240 }, { 18, 2, 10 }, Red);
	CreateCube(60, { 0,1,0 }, { 19, 5, 243 }, { 18, 2, 10 }, Red);
	CreateCube(70, { 0,1,0 }, { 24, 5, 246 }, { 18, 2, 10 }, Red);
	CreateCube(80, { 0,1,0 }, { 29, 5, 246 }, { 18, 2, 10 }, Red);
	CreateCube(90, { 0,1,0 }, { 35, 5, 246 }, { 18, 2, 10 }, Red);
	CreateCube(100, { 0,1,0 }, { 40, 5, 245 }, { 18, 2, 10 }, Red);
	CreateCube(110, { 0,1,0 }, { 45, 5, 243 }, { 18, 2, 10 }, Red);
	CreateCube(120, { 0,1,0 }, { 50, 5, 241 }, { 18, 2, 10 }, Red);
	CreateCube(120, { 0,1,0 }, { 80, 5, 224 }, { 18, 2, 85 }, Red);
	//first curve topes
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { -8, 7, 233 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { -7, 7, 236.5 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { -4, 7, 240 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { -1, 7, 243 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 2.5, 7, 246 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 7, 7, 248 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 12, 7, 250 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 16, 7, 253 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 20, 7, 255 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 26, 7, 255 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 30.5, 7, 255 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 35, 7, 255 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 40, 7, 254 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 45, 7, 253 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 51, 7, 251 }, Red);
	CreateCube(90, { 0,1,0 }, { 35, 5, 235 }, { 25, 2, 55 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 55, 7, 225 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 50, 7, 225 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 45, 7, 225 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 40, 7, 225 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 35, 7, 225 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 30, 7, 225 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 25, 7, 225 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 20, 7, 225 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 15, 7, 225 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 10, 7, 223 }, White);
	CreateCube(120, { 0,1,0 }, { 90, 7, 229 }, { 1, 9, 80 }, Red);
	CreateCube(120, { 0,1,0 }, { 83, 7, 212 }, { 1, 9, 65 }, Red);

	//second curve
	CreateCube(130, { 0,1,0 }, { 118, 5, 202}, { 18, 2, 10 }, Red);
	CreateCube(145, { 0,1,0 }, { 122, 5, 198 }, { 18, 2, 10 }, Red);
	CreateCube(155, { 0,1,0 }, { 126, 5, 191 }, { 18, 2, 10 }, Red);
	CreateCube(165, { 0,1,0 }, { 128, 5, 184 }, { 18, 2, 10 }, Red);
	CreateCube(175, { 0,1,0 }, { 130, 5, 176 }, { 18, 2, 10 }, Red);
	CreateCube(0, { 1,0,0 }, { 130, 5, 160 }, { 18, 2, 30 }, Red);
	CreateCube(0, { 1,0,0 }, { 139, 7, 160 }, { 1, 9, 30 }, Red);
	CreateCube(0, { 1,0,0 }, { 121, 7, 160 }, { 1, 9, 30 }, Red);
	

	//second curve topes
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 127, 7, 207 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 131, 7, 202 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 133.5, 7, 196.5 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 135.5, 7, 190.5 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 136.5, 7, 185.5 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 138.5, 7, 179.5 }, White);
	CreateCube(-25, { 0,1,0 }, { 118, 5, 188 }, { 10, 2, 40 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 112, 7, 194 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 114, 7, 188 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 117, 7, 182 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 119, 7, 176 }, Red);

	//jump to floor level

	CreateCube(0, { 1,0,0 }, { 130, 0, 140 }, { 22, 3, 1 }, White);
	CreateCube(0, { 1,0,0 }, { 141, 0, 90 }, { 1, 3, 100 }, White);
	CreateCube(0, { 1,0,0 }, { 119, 0, 90 }, { 1, 3, 100 }, White);
	CreateCube(0, { 1,0,0 }, { 151, 0, -50 }, { 1, 12, 150 }, White);
	CreateCube(0, { 1,0,0 }, { 109, 0, -50 }, { 1, 12, 150 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 145, 0, 41 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 147, 0, 36 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 149, 0, 31 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 151, 0, 26 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 115, 0, 41 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 113, 0, 36 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 111, 0, 31 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1.8, { 109, 0, 26 }, White);

	//objects to dodge
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 128, 0, 20 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 118, 0, -20 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 135, 0, -30 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 120, 0, -40 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 120, 0, -47 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 140, 0, -50 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 127, 0, -55 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 119, 0, -50 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 137, 0, -65 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 145, 0, -65 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 125, 0, -80 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 115, 0, -88 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 134, 0, -96 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 12, 2, { 127, 0, -120 }, Red);

	//third curve
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 118, 0, -168 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 124, 0, -167 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 128, 0, -163 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 132, 0, -159 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 136, 0, -155 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 141, 0, -150 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 145, 0, -145 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 147, 0, -140 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 149, 0, -135 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 151, 0, -130 }, White);

	
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 99, 0, -150 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 103, 0, -145 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 105, 0, -140 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 107, 0, -135 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 2.2, { 109, 0, -130 }, White);

	//final rect
	CreateCube(0, { 1,0,0 }, { 49, 0, -150 }, { 100, 3, 1 }, White);
	CreateCube(0, { 1,0,0 }, { 59, 0, -167 }, { 120, 3, 1 }, White);
	
	//final jump
	CreateCube(0, { 0,1,0 }, { 1.9, 0, -158 }, { 2, 0.1, 15 }, Red);
	CreateCube(-10, { 0,0,1 }, { 0, 0.1, -158 }, { 2, 0.1, 15 }, Red);
	CreateCube(-15, { 0,0,1 }, { -1.9, 0.5, -158}, { 2, 0.1, 15 }, Red);
	CreateCube(-25, { 0,0,1 }, { -3.7, 1.1, -158}, { 2, 0.1, 15 }, Red);
	CreateCube(-30, { 0,0,1 }, { -5.4, 2, -158}, { 2, 0.1, 15 }, Red);

	//WINNING STAGE
	CreateCube(0, { 0,1,0 }, { -140, 0, -158 }, { 60, 5, 20 }, Red);
	CreateCube(0, { 0,1,0 }, { -140, 10, -148 }, { 20, 35, 1 }, Red);
	CreateCube(0, { 0,1,0 }, { -140, 10, -168 }, { 20, 35, 1 }, Red);
	CreateCube(0, { 0,1,0 }, { -140, 28, -158 }, { 20, 1, 20 }, Red);
	CreateCube(0, { 0,1,0 }, { -170, 10, -158 }, { 1, 15, 20 }, Red);
	CreateCube(0, { 0,1,0 }, { -160, 5, -148 }, { 20, 10, 1 }, Red);
	CreateCube(0, { 0,1,0 }, { -160, 5, -168 }, { 20, 10, 1 }, Red);








	




	
	

	
	
	
	//CreateCylinder(90, { 0, 0, 1 }, 8, 2, { 0, 1, 10 }, Red);




	colliderscreated = true;
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

//create walls for the straight zones of the map(function)
void ModuleSceneIntro::CreateCube(int angle1, vec3 angle, vec3 offset, vec3 size, Color color)
{
	Cube cube;
	cube.size = size;
	cube.SetPos(offset.x, offset.y, offset.z);
	cube.color = color;
	cube.SetRotation(angle1, angle);
	if (colliderscreated == false) {
		App->physics->AddBody(cube, 0);
	}
	cube.Render();
}

//create walls for the curve zones of the map(function)
void ModuleSceneIntro::CreateCylinder(float angle1, vec3 angle, float altura, float radi, vec3 offset, Color color)
{
	Cylinder cylinder;
	cylinder.radius = radi;
	cylinder.height = altura;
	cylinder.SetPos(offset.x, offset.y, offset.z);
	cylinder.color = color;
	cylinder.SetRotation(angle1, angle);
	if (colliderscreated == false) {
		App->physics->AddBody(cylinder, 0);
	}
	cylinder.Render();

}



	


#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
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

	//no exit line(backwards)
	CreateCube(0, { 0,1,0 }, { 0, 0, -9.5 }, { 14, 5, 1}, White);
	//start zone
	CreateCube(0, { 0,1,0 }, { 0, 0, 0}, { 14, 0.1, 10 }, Red);
	//"race" map
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
	CreateCylinder(90, { 0, 0, 1 }, 8, 1, { -8, 7, 233 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1, { -7, 7, 236.5 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1, { -4, 7, 240 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1, { -1, 7, 243 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1, { 2.5, 7, 246 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1, { 7, 7, 248 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1, { 12, 7, 250 }, Red);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1, { 16, 7, 253 }, White);
	CreateCylinder(90, { 0, 0, 1 }, 8, 1, { 20, 7, 255 }, Red);




	CreateCube(120, { 0,1,0 }, { 90, 7, 229 }, { 1, 9, 80 }, Red);
	CreateCube(120, { 0,1,0 }, { 83, 7, 212 }, { 1, 9, 75 }, Red);

	
	
	
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



	


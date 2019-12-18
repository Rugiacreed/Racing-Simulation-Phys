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






	colliderscreated = true;
	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

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



	


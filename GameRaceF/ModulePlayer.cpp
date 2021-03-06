#include "Globals.h"
#include "Application.h"
#include "ModulePlayer.h"
#include "Primitive.h"
#include "PhysVehicle3D.h"
#include "PhysBody3D.h"
#include "ModuleSceneIntro.h"

ModulePlayer::ModulePlayer(Application* app, bool start_enabled) : Module(app, start_enabled), vehicle(NULL)
{
	turn = acceleration = brake = 0.0f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");

	VehicleInfo car;

	// Car properties ----------------------------------------
	
	//main chassis
	car.chassis_size.Set(2, 0.8, 4);
	car.chassis_offset.Set(0, 0.7, 0);
	car.chassis2_size.Set(1.2, 0.8, 3.5);
	car.chassis2_offset.Set(0, 1, -0.2);
	car.chassis3_size.Set(0.2, 0.3, 2);
	car.chassis3_offset.Set(0, 1.5, -1.2);
	
	//front chassis
	car.frontcube_size.Set(2, 0.4, 1.5);
	car.frontcube_offset.Set(0, 0.5, 2);

	//"aleron" for the car 
	car.backcube_size.Set(3.2, 0.4, 0.7);
	car.backcube_offset.Set(0, 1.2, -2.6);
	car.backcubereinforce1_size.Set(0.2, 0.2, 0.7);
	car.backcubereinforce1_offset.Set(-1, 0.9, -2.2);
	car.backcubereinforce2_size.Set(0.2, 0.2, 0.7);
	car.backcubereinforce2_offset.Set(1, 0.9, -2.2);

	//car characteristics
	car.mass = 400.0f;
	car.suspensionStiffness = 25.88f;
	car.suspensionCompression = 2.00f;
	car.suspensionDamping = 2.00f;
	car.maxSuspensionTravelCm = 1000.0f;
	car.frictionSlip = 50.5;
	car.maxSuspensionForce = 6000.0f;

	// Wheel properties ---------------------------------------
	float connection_height = 1.2f;
	float wheel_radius = 0.6f;
	float wheel_width = 0.5f;
	float suspensionRestLength = 1.2f;

	// Don't change anything below this line ------------------

	float half_width = car.chassis_size.x*0.7f;
	float half_length = car.chassis_size.z*0.5f;
	
	vec3 direction(0,-1,0);
	vec3 axis(-1,0,0);
	
	car.num_wheels = 4;
	car.wheels = new Wheel[4];

	// FRONT-LEFT ------------------------
	car.wheels[0].connection.Set(half_width - 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[0].direction = direction;
	car.wheels[0].axis = axis;
	car.wheels[0].suspensionRestLength = suspensionRestLength;
	car.wheels[0].radius = wheel_radius;
	car.wheels[0].width = wheel_width;
	car.wheels[0].front = true;
	car.wheels[0].drive = true;
	car.wheels[0].brake = false;
	car.wheels[0].steering = true;

	// FRONT-RIGHT ------------------------
	car.wheels[1].connection.Set(-half_width + 0.3f * wheel_width, connection_height, half_length - wheel_radius);
	car.wheels[1].direction = direction;
	car.wheels[1].axis = axis;
	car.wheels[1].suspensionRestLength = suspensionRestLength;
	car.wheels[1].radius = wheel_radius;
	car.wheels[1].width = wheel_width;
	car.wheels[1].front = true;
	car.wheels[1].drive = true;
	car.wheels[1].brake = false;
	car.wheels[1].steering = true;

	// REAR-LEFT ------------------------
	car.wheels[2].connection.Set(half_width - 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[2].direction = direction;
	car.wheels[2].axis = axis;
	car.wheels[2].suspensionRestLength = suspensionRestLength;
	car.wheels[2].radius = wheel_radius;
	car.wheels[2].width = wheel_width;
	car.wheels[2].front = false;
	car.wheels[2].drive = false;
	car.wheels[2].brake = true;
	car.wheels[2].steering = false;

	// REAR-RIGHT ------------------------
	car.wheels[3].connection.Set(-half_width + 0.3f * wheel_width, connection_height, -half_length + wheel_radius);
	car.wheels[3].direction = direction;
	car.wheels[3].axis = axis;
	car.wheels[3].suspensionRestLength = suspensionRestLength;
	car.wheels[3].radius = wheel_radius;
	car.wheels[3].width = wheel_width;
	car.wheels[3].front = false;
	car.wheels[3].drive = false;
	car.wheels[3].brake = true;
	car.wheels[3].steering = false;

	vehicle = App->physics->AddVehicle(car);
	vehicle->SetPos(0, 5, 0);
	
	return true;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	return true;
}

// Update: draw background
update_status ModulePlayer::Update(float dt)
{
	turn = acceleration = brake = 0.0f;

//stop from going backwards+acceleration forward
	if(App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
	{
		if (vehicle->GetKmh() < -7) {
			brake = -BRAKE_POWER;
		}
		else {
		
			acceleration = MAX_ACCELERATION;
		
		}
		
	}

	if(App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
	{
		if(turn < TURN_DEGREES)
			turn +=  TURN_DEGREES;
	}

	if(App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
	{
		if(turn > -TURN_DEGREES)
			turn -= TURN_DEGREES;
	}
//stop from going forwards+acceleration backwards
	if(App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
	{
		if (vehicle->GetKmh() > 3.5) {
			brake = BRAKE_POWER;
		}
		else {
			acceleration = -MAX_ACCELERATION;
		}
			
	}

	vehicle->ApplyEngineForce(acceleration);
	vehicle->Turn(turn);
	vehicle->Brake(brake);

	vehicle->Render();

	
	if (App->scene_intro->winner == true) {
		App->window->SetTitle("You Win Motherfucker");
	}
	else {
		char title[80];
		sprintf_s(title, "%.1f Km/h", vehicle->GetKmh());
		App->window->SetTitle(title);
	}
	

	

	return UPDATE_CONTINUE;
}




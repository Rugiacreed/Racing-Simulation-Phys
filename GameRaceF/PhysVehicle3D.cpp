#include "PhysVehicle3D.h"
#include "Primitive.h"
#include "Bullet/include/btBulletDynamicsCommon.h"

// ----------------------------------------------------------------------------
VehicleInfo::~VehicleInfo()
{
	//if(wheels != NULL)
		//delete wheels;
}

// ----------------------------------------------------------------------------
PhysVehicle3D::PhysVehicle3D(btRigidBody* body, btRaycastVehicle* vehicle, const VehicleInfo& info) : PhysBody3D(body), vehicle(vehicle), info(info)
{
}

// ----------------------------------------------------------------------------
PhysVehicle3D::~PhysVehicle3D()
{
	delete vehicle;
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Render()
{
	Cylinder wheel;

	wheel.color = Blue;

	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		wheel.radius = info.wheels[0].radius;
		wheel.height = info.wheels[0].width;

		vehicle->updateWheelTransform(i);
		vehicle->getWheelInfo(i).m_worldTransform.getOpenGLMatrix(&wheel.transform);

		wheel.Render();
	}

	Cube chassis(info.chassis_size.x, info.chassis_size.y, info.chassis_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&chassis.transform);
	btQuaternion q = vehicle->getChassisWorldTransform().getRotation();
	btVector3 offset(info.chassis_offset.x, info.chassis_offset.y, info.chassis_offset.z);
	offset = offset.rotate(q.getAxis(), q.getAngle());
	chassis.transform.M[12] += offset.getX();
	chassis.transform.M[13] += offset.getY();
	chassis.transform.M[14] += offset.getZ();
	chassis.color = Purple;
	chassis.Render();

	Cube frontcube(info.frontcube_size.x, info.frontcube_size.y, info.frontcube_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&frontcube.transform);
	btVector3 offsetfrontcube(info.frontcube_offset.x, info.frontcube_offset.y, info.frontcube_offset.z);
	offsetfrontcube = offsetfrontcube.rotate(q.getAxis(), q.getAngle());
	frontcube.transform.M[12] += offsetfrontcube.getX();
	frontcube.transform.M[13] += offsetfrontcube.getY();
	frontcube.transform.M[14] += offsetfrontcube.getZ();
	frontcube.color = Purple;
	frontcube.Render();
	
	Cube backcube(info.backcube_size.x, info.backcube_size.y, info.backcube_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&backcube.transform);
	btVector3 offsetbackcube(info.backcube_offset.x, info.backcube_offset.y, info.backcube_offset.z);
	offsetbackcube = offsetbackcube.rotate(q.getAxis(), q.getAngle());
	backcube.transform.M[12] += offsetbackcube.getX();
	backcube.transform.M[13] += offsetbackcube.getY();
	backcube.transform.M[14] += offsetbackcube.getZ();
	backcube.color = Purple;
	backcube.Render();

	Cube backcubereinforce1(info.backcubereinforce1_size.x, info.backcubereinforce1_size.y, info.backcubereinforce1_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&backcubereinforce1.transform);
	btVector3 offsetbackcubereinforce1(info.backcubereinforce1_offset.x, info.backcubereinforce1_offset.y, info.backcubereinforce1_offset.z);
	offsetbackcubereinforce1 = offsetbackcubereinforce1.rotate(q.getAxis(), q.getAngle());
	backcubereinforce1.transform.M[12] += offsetbackcubereinforce1.getX();
	backcubereinforce1.transform.M[13] += offsetbackcubereinforce1.getY();
	backcubereinforce1.transform.M[14] += offsetbackcubereinforce1.getZ();
	backcubereinforce1.color = Purple;
	backcubereinforce1.Render();

	Cube backcubereinforce2(info.backcubereinforce2_size.x, info.backcubereinforce2_size.y, info.backcubereinforce2_size.z);
	vehicle->getChassisWorldTransform().getOpenGLMatrix(&backcubereinforce2.transform);
	btVector3 offsetbackcubereinforce2(info.backcubereinforce2_offset.x, info.backcubereinforce2_offset.y, info.backcubereinforce2_offset.z);
	offsetbackcubereinforce2 = offsetbackcubereinforce2.rotate(q.getAxis(), q.getAngle());
	backcubereinforce2.transform.M[12] += offsetbackcubereinforce2.getX();
	backcubereinforce2.transform.M[13] += offsetbackcubereinforce2.getY();
	backcubereinforce2.transform.M[14] += offsetbackcubereinforce2.getZ();
	backcubereinforce2.color = Purple;
	backcubereinforce2.Render();
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::ApplyEngineForce(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].drive == true)
		{
			vehicle->applyEngineForce(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Brake(float force)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].brake == true)
		{
			vehicle->setBrake(force, i);
		}
	}
}

// ----------------------------------------------------------------------------
void PhysVehicle3D::Turn(float degrees)
{
	for(int i = 0; i < vehicle->getNumWheels(); ++i)
	{
		if(info.wheels[i].steering == true)
		{
			vehicle->setSteeringValue(degrees, i);
		}
	}
}

// ----------------------------------------------------------------------------
float PhysVehicle3D::GetKmh() const
{
	return vehicle->getCurrentSpeedKmHour();
}
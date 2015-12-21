
#pragma once
#include <DirectXMath.h>

using namespace DirectX;

class Transform{

public:
	Transform(){
		// set default values
		XMMATRIX ident = XMMatrixIdentity();
		XMStoreFloat4x4(&this->wMatrix, ident);

		XMStoreFloat3(&position, XMVectorZero());
		XMStoreFloat3(&rotation, XMVectorZero());
		XMStoreFloat3(&scale, XMVectorSet(1, 1, 1, 1));

		isDirty = false;
	}

	~Transform(){}

#pragma region Transforms

	// add _value to position, return result
	XMFLOAT3 Move(XMFLOAT3 _value){
		// Load vectors
		XMVECTOR pos = XMLoadFloat3(&position);
		XMVECTOR _val = XMLoadFloat3(&_value);

		// calculate new position
		pos = pos + _val;
		XMStoreFloat3(&position, pos);

		// update flag
		isDirty = true;

		return position;
	}

	XMFLOAT3 MoveForward(float amt) {
		XMVECTOR forward = XMLoadFloat3(&GetDirection());
		forward = XMVectorScale(forward, amt);

		XMVECTOR curPosition = XMLoadFloat3(&position);
		XMStoreFloat3(&position, XMVectorAdd(curPosition, forward));

		// Update flag
		isDirty = true;

		return position;
	}

	XMFLOAT3 MoveBackward(float amt) {
		return this->MoveForward(amt * -1);
	}

	XMFLOAT3 StrafeLeft(float amt) {
		XMVECTOR forward = XMLoadFloat3(&GetDirection());
		XMVECTOR direction = XMVector3Cross(forward, XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f));

		XMVECTOR offset = XMVectorScale(direction, amt);

		XMVECTOR curPosition = XMLoadFloat3(&position);
		XMStoreFloat3(&position, XMVectorAdd(curPosition, offset));

		// Update flag
		isDirty = true;

		return position;
	}

	XMFLOAT3 StrafeRight(float amt) {
		return StrafeLeft(amt * -1);
	}

	// modify rotation vector, return result
	XMFLOAT3 Rotate(XMFLOAT3 _value){
		// Load vectors
		XMVECTOR rot = XMLoadFloat3(&rotation);
		XMVECTOR _val = XMLoadFloat3(&_value);

		// Calculate new rotation
		rot = rot + _val;
		XMStoreFloat3(&rotation, rot);

		// Update flag
		isDirty = true;

		return rotation;
	}

	XMFLOAT3 RotateClampX(XMFLOAT3 _value, float _min, float _max) {
		XMFLOAT3 rot = this->Rotate(_value);

		rot.x = max(min(rot.x, _min), _max);

		return rot;
	}

	// modify scale vector, return result
	XMFLOAT3 Scale(XMFLOAT3 _value){
		// Load vectors
		XMVECTOR scal = XMLoadFloat3(&scale);
		XMVECTOR _val = XMLoadFloat3(&_value);

		// Calculate new rotation
		scal = scal + _val;
		XMStoreFloat3(&scale, scal);

		// Update flag
		isDirty = true;

		return scale;
	}

#pragma endregion

#pragma region Getters and Setters

	XMFLOAT3 GetPostion(){ return this->position; }
	XMFLOAT3 GetRotation(){ return this->rotation; }
	XMFLOAT3 GetScale(){ return this->scale; }
	
	XMFLOAT3 GetDirection() {
		XMMATRIX mRotation = XMMatrixRotationRollPitchYaw(rotation.x, rotation.y, 0.0f);
		XMVECTOR vDir = XMVectorSet(0.0f, 0.0f, 1.0f, 0.0f);
		 vDir =  XMVector3Transform(vDir, mRotation);

		XMStoreFloat3(&direction, vDir);
		
		return direction;
	}

	XMFLOAT4X4 GetMatrix() { 
		// Has the matrix changed?
		if (isDirty) {
			// Re-calculate the matrix
			calcuateMatrix();

			// Reset flag
			isDirty = false;
		}

		return this->wMatrix; 
	}

	void SetPostion(XMFLOAT3 _position) { 
		this->position = _position;
		isDirty = true;
	}

	void SetRotation(XMFLOAT3 _rotation) { 
		this->rotation = _rotation; 
		isDirty = true;
	}

	void SetScale(XMFLOAT3 _scale) { 
		this->scale = _scale; 
		isDirty = true;
	}

	bool GetIsDirty() {
		return isDirty;
	}

#pragma endregion

protected:
	// Transform vars
	XMFLOAT4X4 wMatrix;	// World Matrix
	XMFLOAT3 position;
	XMFLOAT3 scale;
	XMFLOAT3 rotation;
	XMFLOAT3 direction;

	XMFLOAT2 xRotClamp;
	XMFLOAT2 yRotClamp;

	// Flags
	bool isDirty;	// If the world matrix is outdated and needs to be recalculated
	bool rotClamp;	// If the rotation has a clamp set

	// Calculates the transform's world matrix based on the position, scale, and rotation vectors
	XMFLOAT4X4 calcuateMatrix() {

		XMMATRIX mTrans = XMMatrixTranslation(position.x, position.y, position.z);
		XMMATRIX mRotX = XMMatrixRotationX(rotation.x);
		XMMATRIX mRotY = XMMatrixRotationY(rotation.y);
		XMMATRIX mRotZ = XMMatrixRotationZ(rotation.z);
		XMMATRIX mScale = XMMatrixScaling(scale.x, scale.y, scale.z);

		// Multiple each matrix to get world matrix
		XMMATRIX mWorld = mScale * mRotZ * mRotY * mRotX * mTrans;

		// Transpose and store new world matrix
		XMStoreFloat4x4(&wMatrix, XMMatrixTranspose(mWorld));

		return wMatrix;
	}
};

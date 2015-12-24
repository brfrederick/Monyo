#pragma once
#include "IRenderStep.h"

class GeometryStep : public IRenderStep
{
public:
	GeometryStep() {};
	~GeometryStep() {};

	virtual void Render() override;

private:
	virtual void Pre() override;
	virtual void Post() override;
};
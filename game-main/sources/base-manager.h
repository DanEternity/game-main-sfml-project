#pragma once

class BaseManager
{
public:

	bool levelInitRequired = true;

	virtual void Update(); // Primary update method
	virtual void Init(); // Primary init method
	virtual void Destroy(); // Primary destroy 

};
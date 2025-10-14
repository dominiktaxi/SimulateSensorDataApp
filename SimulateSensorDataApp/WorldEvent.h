#pragma once
class WorldEvent
{
public:
	enum class EVENT { TEMPERATURE_TOO_HIGH };
	WorldEvent() = default;
	EVENT event() const;
private:
	EVENT _event;
};


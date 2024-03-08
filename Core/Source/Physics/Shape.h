#pragma once

class Shape
{
public:
    enum Type
    {
        Circle = 1,
    };
    Shape(Type shapeType) {m_Type = shapeType;}
/**
 * 
 * @return {Type}  : 
 */
	inline Type GetType() const
	{
		return m_Type;
	}
private:
	Type m_Type;
};


#pragma once

namespace Helio
{
	class Vector2
	{
	public:
		double x;
		double y;

		Vector2() : x(0), y(0) {}

		Vector2(double X, double Y)
			: x(X), y(Y) {}
	};
}
#pragma once

#include <stdint.h>

namespace Helio
{
	class Bitmask
	{
	private:
		uint32_t bits;

	public:

		Bitmask();

		void SetMask(Bitmask& other);

		uint32_t GetMask() const;

		bool GetBit(int pos) const;

		void SetBit(int pos, bool on);

		void SetBit(int pos);

		void ClearBit(int pos);

		void Clear();
	};
}
import "math"
func divide(dividend int, divisor int) int {
	if divisor == 0 {
		panic("division by zero")
	}

	if dividend == math.MinInt32 && divisor == -1 {
		return math.MaxInt32
	}

	sign := 1
	if (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0) {
		sign = -1
	}

	// Convert both dividend and divisor to positive values
	absDividend := int64(math.Abs(float64(dividend)))
	absDivisor := int64(math.Abs(float64(divisor)))

	// Perform division using bitwise shifts
	quotient := int64(0)
	for absDividend >= absDivisor {
		tempDivisor := absDivisor
		multiple := int64(1)
		for absDividend >= (tempDivisor << 1) {
			tempDivisor <<= 1
			multiple <<= 1
		}
		absDividend -= tempDivisor
		quotient += multiple
	}

	if sign < 0 {
		quotient = -quotient
	}

	// Ensure the result fits in a 32-bit signed integer
	if quotient > math.MaxInt32 {
		return math.MaxInt32
	} else if quotient < math.MinInt32 {
		return math.MinInt32
	}
	return int(quotient)

}
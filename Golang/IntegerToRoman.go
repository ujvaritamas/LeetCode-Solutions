package main

import (
	"fmt"
	"strings"
	"time"
)

type RomanRepresetation struct {
	RomanFormat string
	IntFormat   int
}

var RomanNumbers100 = [...]RomanRepresetation{
	RomanRepresetation{"CM", 900},
	RomanRepresetation{"D", 500},
	RomanRepresetation{"CD", 400},
	RomanRepresetation{"C", 100},
}

const divider100 = 100

var RomanNumbers10 = [...]RomanRepresetation{
	RomanRepresetation{"XC", 90},
	RomanRepresetation{"L", 50},
	RomanRepresetation{"XL", 40},
	RomanRepresetation{"X", 10},
}

const divider10 = 10

var RomanNumbers1 = [...]RomanRepresetation{
	RomanRepresetation{"IX", 9},
	RomanRepresetation{"V", 5},
	RomanRepresetation{"IV", 4},
	RomanRepresetation{"I", 1},
}

const divider1 = 1

func (number RomanRepresetation) getRecalculatedIntFormat(divider int) int {
	return number.IntFormat / divider
}

func calculateRoman1000(num int, res string) (string, int) {
	res += strings.Repeat("M", int(num/1000))
	num = num % 1000

	return res, num
}

func calculateRomanSmaller1000(num int, values []RomanRepresetation, divider int, res string) (string, int) {
	div := int(num / divider)
	if div == values[0].getRecalculatedIntFormat(divider) { //9
		res += values[0].RomanFormat
	} else if div > values[1].getRecalculatedIntFormat(divider) { //6, 7, 8
		res += values[1].RomanFormat
		res += strings.Repeat(values[3].RomanFormat, int(div-5))
	} else if div == values[1].getRecalculatedIntFormat(divider) { //5
		res += values[1].RomanFormat
	} else if div == values[2].getRecalculatedIntFormat(divider) { //4
		res += values[2].RomanFormat
	} else { //0, 1, 2, 3
		res += strings.Repeat(values[3].RomanFormat, int(div))
	}
	num = num % divider

	return res, num
}

func intToRoman(num int) string {
	res := ""

	res, num = calculateRoman1000(num, res)
	res, num = calculateRomanSmaller1000(num, RomanNumbers100[:], divider100, res)
	res, num = calculateRomanSmaller1000(num, RomanNumbers10[:], divider10, res)
	res, _ = calculateRomanSmaller1000(num, RomanNumbers1[:], divider1, res)

	return res
}

func main() {

	r := ""
	testNumber := 7444

	start := time.Now()
	for i := 0; i < 10000; i++ {
		r = intToRoman(testNumber)
	}
	elapsed := time.Since(start)

	fmt.Println("Test number: ", testNumber)
	fmt.Println(r)
	fmt.Println(elapsed)

}

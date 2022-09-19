package main

func main() {
	mainVal := foo(666)
	println(*mainVal, mainVal)
}

func foo(val int) *int {
	val1 := 11
	val2 := 12
	val3 := 13
	val4 := 14
	val5 := 15

	for i := 0; i < 5; i++ {
		println(&val, &val1, &val2, &val3, &val4, &val5)
	}
	return &val3
}

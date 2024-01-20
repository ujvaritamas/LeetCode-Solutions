//go mod init <rootdir>, go mod tidy
package main

import "fmt"
import (
	"rsc.io/quote"
	"mymodule/greetings"
	"log"
)

func main(){
	fmt.Println("hello")
	fmt.Println(quote.Go())
	myModuleMessage, err := greetings.Hello("")

	if err != nil {
        log.Fatal(err)
    }

	fmt.Println(myModuleMessage)
}
package main

import (
	"errors"
	"fmt"
	"sync"
	"time"
)

type Node struct {
    value int
    next *Node 
}

type LinkedList struct {
    Head *Node
    Temp *Node
    Size int
}

func returner() *LinkedList {
    return &LinkedList{}
}

func (l *LinkedList) Append(value int) {
    newnode := new(Node)
    newnode.value = value

    //newnode.next = nil //because it is redundant already nil

    if l.Head == nil {
        l.Head = newnode
        l.Temp = newnode
    } else {
        l.Temp.next = newnode
        l.Temp = l.Temp.next
    }
}

func (l *LinkedList) Prepend(value int) {
    l.Temp = l.Head

    newnode := new(Node)
    newnode.value = value
    l.Head = newnode
    l.Head.next = l.Temp
}

func (l *LinkedList) Delete(value int) (bool, error) {
    if l.Head == nil {
        return false, errors.New("NO NODE IN THE LIST")
    }

    if l.Head.value == value {
        l.Head = l.Head.next
        return true, nil
    }

    prev := new(Node)
    l.Temp = l.Head.next
    prev = l.Head

    for l.Temp.next != nil {
        if value == l.Temp.value {
            prev.next = l.Temp.next
            return true, nil
        }

        prev = l.Temp
        l.Temp = l.Temp.next
    }

    if l.Temp.value == value {
        prev.next = nil
        return true, nil
    } else {
        err := errors.New("NO SUCH NODE IN THE LIST")
        return false, err
    }
}

func (l LinkedList) Print() {
    l.Temp = l.Head

    for l.Temp.next != nil {
        fmt.Println(l.Temp.value, "->")
        l.Temp = l.Temp.next
    }
    fmt.Println(l.Temp.value)
}

func main() {
    var once sync.Once
    var wg sync.WaitGroup

    a := returner()

    a.Append(1)
    a.Append(2)
    a.Append(3)
    a.Prepend(4)

    wg.Add(1)
	go func() {
		defer wg.Done()
        once.Do(func() {
            if _, err := a.Delete(2); err != nil { //can specify your number to delete
                fmt.Println(err)
            }
        })
    }()

    time.Sleep(time.Second * 1)

    a.Print()
}

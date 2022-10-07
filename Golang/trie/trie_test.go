package trie

import (
	"fmt"
	"testing"
)

func TestTrie(t *testing.T) {
	trie := NewTrie()
	trie.Insert("apple")
	fmt.Println(trie.StartWith("app"))
	fmt.Println(trie.SearchWord("app"))
	fmt.Println(trie.SearchWord("apple"))
}

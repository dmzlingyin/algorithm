package trie

type Trie struct {
	Children [26]*Trie
	IsEnd    bool
}

func NewTrie() *Trie {
	return &Trie{}
}

func (t *Trie) Insert(word string) {
	node := t
	for _, ch := range word {
		ch -= 'a'
		if node.Children[ch] == nil {
			node.Children[ch] = &Trie{}
		}
		node = node.Children[ch]
	}
	node.IsEnd = true
}

func (t *Trie) SearchWord(word string) bool {
	node := t.SearchPrefix(word)
	return node != nil && node.IsEnd == true
}

func (t *Trie) StartWith(prefix string) bool {
	return t.SearchPrefix(prefix) != nil
}

func (t *Trie) SearchPrefix(prefix string) *Trie {
	node := t
	for _, ch := range prefix {
		ch -= 'a'
		if node.Children[ch] == nil {
			return nil
		}
		node = node.Children[ch]
	}
	return node
}

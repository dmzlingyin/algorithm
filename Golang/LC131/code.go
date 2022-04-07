// 力扣131, 分割回文串
package LC131

var res [][]string

func partition(s string) [][]string {
	res = [][]string{}
	if len(s) <= 0 {
		return res
	}

	backTrack(s, 0, []string{})
	return res
}

func backTrack(s string, start int, track []string) {
	if start >= len(s) {
		temp := make([]string, len(track))
		copy(temp, track)
		res = append(res, temp)
		return
	}

	for i := start; i < len(s); i++ {
		if !isPartition(s, start, i) {
			continue
		}
		track = append(track, s[start:i+1])
		backTrack(s, i+1, track)
		track = track[:len(track)-1]
	}
}

func isPartition(s string, left, right int) bool {
	for left <= right {
		if s[left] != s[right] {
			return false
		}
		left++
		right--
	}
	return true
}

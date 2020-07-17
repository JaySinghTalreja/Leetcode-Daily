// https://code.dennyzhang.com/shortest-way-to-form-string
// Basic Ideas: slide window
//
// Notice: 
//  - how to detect not found?
//
// Complexity: Time O(n^2), Space O(n)
func shortestWay(source string, target string) int {
    res := 0
    i:=0
    for i<len(target) {
        exists := false
        for j:=0; j<len(source); j++ {
            if i<len(target) && source[j] == target[i] {
                exists = true
                i++
            }
        }
        if !exists {
            return -1
        }
        res++
    }
    return res
}
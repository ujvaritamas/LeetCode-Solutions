import "strings"

func strStr(haystack string, needle string) int {
	index := strings.Index(haystack, needle)

	return index
}
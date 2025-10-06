/**
 * @param {string} s
 * @return {string}
 */
function isVowel(c) {
  const lC = c.toLowerCase()
  return lC == 'a' || lC == 'e' || lC == 'i' || lC == 'o' || lC == 'u'
}

var reverseVowels = function (s) {
  let sArray = s.split('')
  let left = 0, right = sArray.length - 1

  while (left < right) {
    while (left < right && !isVowel(sArray[left])) {
      left++
    }

    while (left < right && !isVowel(sArray[right])) {
      right--
    }

    if (left < right) {
      let temp = sArray[left]
      sArray[left] = sArray[right]
      sArray[right] = temp

      left++
      right--
    }
  }

  return sArray.join('')
};

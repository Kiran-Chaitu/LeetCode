class Solution {
    public boolean doesAliceWin(String s) {
        int vowelsCount =0 ;
        HashMap<Character, Integer> hashMap = new HashMap<>();
        char[] vowels = {'a','e','i','o','u'};
        for(int i =0 ; i < 5 ; i++){
            hashMap.put(vowels[i],1);
        }
        for(int i =0 ; i < s.length();i++){
            if(hashMap.containsKey(s.charAt(i))) vowelsCount++;
        }
        return (vowelsCount  > 0) ;
    }
}
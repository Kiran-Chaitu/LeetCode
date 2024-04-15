class Solution {
    public int strStr(String haystack, String needle) {
        int haystackLength = haystack.length();
        int needleLength = needle.length();
        if(haystackLength == needleLength){
            if(haystack.equals(needle)) return 0;
            else return -1;
        }
        for(int i=0;i<=haystackLength - needleLength;i++){
            String subString = haystack.substring(i,i+needleLength);
            //System.out.println(subString);
            if(subString.equals(needle)) return i;
        }
        return -1;
    }
}
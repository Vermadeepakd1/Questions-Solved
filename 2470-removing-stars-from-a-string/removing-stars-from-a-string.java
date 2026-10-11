class Solution {
    public String removeStars(String s) {
        Deque<Character>stack = new ArrayDeque<>();

        for(char ch : s.toCharArray()){
            if(ch == '*')stack.pop();
            else stack.push(ch);
        }

        StringBuilder sb = new StringBuilder();
        while(!stack.isEmpty()){
            sb.append(stack.pop());
        }
        String ans = sb.reverse().toString();
        return ans;
    }
}
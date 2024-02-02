class ZigZagConv{
    public String convert(String s, int numRows) {
        if(numRows == 1){
            return s;
        }

        String ret = "";
        String[] rows = new String[numRows];
        boolean isCountDown = false;
        int maxIndex = numRows -1;
        int index = 0;

        for (int i = 0; i < numRows; i++){
            rows[i] = "";
        }
        for (int i = 0; i < s.length(); i++){
            char c = s.charAt(i);

            rows[index] += c;

            if(isCountDown){
                if(index == 0){
                    isCountDown = false;
                    index++;
                }
                else{
                    index--;
                }
            }
            else{
                if(index == maxIndex){
                    isCountDown = true;
                    index--;
                }
                else{
                    index++;
                }
            }

        }
        for(int i = 0; i<numRows; i++){
                ret += rows[i];
        }
        return ret;
    }

}
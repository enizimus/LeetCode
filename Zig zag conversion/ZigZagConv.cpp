class Solution {
public:
    string convert(string text, int nRows) {
        

	if (nRows > 1) {
		int char_in_pattern = 2 * nRows - 2;
		int pattern_len = nRows - 1;
		int dev_col = text.length() % char_in_pattern;
		int min_patt = text.length() / char_in_pattern;
		int max_patt = (dev_col) ? min_patt + 1 : min_patt;

		int min_col = 0;
		if (dev_col) {
			min_col = (dev_col <= nRows) ? pattern_len - 1 : pattern_len - (dev_col - nRows + 1);
		}

		int nCols = (max_patt*pattern_len - min_col);

		vector<vector<char>> zig_zag(nRows, vector<char>(nCols, 0));

		int index = 0, j = 0, k = 0;
		for (int i = 0; i<max_patt && index<text.length(); i++) {

			for (; j<nRows && index<text.length(); j++) {
				zig_zag[j][k] = text[index];
				index++;
			}
			j-=2;
			k++;
			for (; j>0 && index<text.length(); j--, k++) {
				zig_zag[j][k] = text[index];
				index++;
			}
		}
		index = 0;
		for (int i = 0; i<nRows; i++) {
			for (int j = 0; j<nCols; j++) {
				if (zig_zag[i][j] != '\0') {
					text[index++] = zig_zag[i][j];
					
				}
				
			}
		}
	}
	
    
    return text;
    }
};
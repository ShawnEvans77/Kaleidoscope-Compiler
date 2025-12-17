// when we want to compile a language, the first thing that must be done is parsing tokens to understand
// what they are. categorizing keywords appropiately. this is the job of a "LEXER."

// we will be compiling KALEIDOSCOPE, where the only thing of note is a 64-bit floating point type.

// each token from the lexer includes a TOKEN CODE and potentially some meta data. let us now define the possibilities.

#include <string>

enum Token {
    tok_EOF = -1, // end of file.

    // commands.
    // like defining a function. 
    tok_def = -2,
    tok_extern = -3,

    // primary
    tok_identifier = -4,
    tok_number = -5,
};

static std::string identifier_str; // we fill this in if we see a token identifer. 
static double num_val; // we fill this in if we see a numeric value. 

static int get_token() {

    // get token will be a function to fetch functions from standard input. 

    static int last_char = ' ';

    // we skip whitecase, fetching appropiate tokens. 

    while (isspace(last_char)) {
        last_char = std::getchar(); // we are reading characters one at a time from standard input. 
        // std::getchar is a cpp function to recieve a char from standard input.

        if (std::isalpha(last_char)) { // if the current character is alphanumeric. 

            identifier_str = last_char;

            while (std::isalnum(last_char = std::getchar())) { // as long as the next characters read in are alphanumeric.
                identifier_str += last_char;
            }

            if (identifier_str == "def")
                return tok_def;
            else if (identifier_str == "extern")
                return tok_extern;

            return tok_identifier; 
        }

        if (std::isdigit(last_char)) { // if the current character is a digit,
            std::string num_string;

            do {
                num_string += last_char;
                last_char = std::getchar();
            } while (std::isdigit(last_char) || last_char == '.');

            // we construct a num_string by simply reading a 

            num_val = std::strtod(num_string.c_str(), 0);
            // the cpp strtod function is how we can convert a numerical string into to a double value

            return tok_number;
        }

        if (last_char == '#') { // if the current character is a comment, 

            // this line skips past the comment.
            do {
                last_char = std::getchar();
            } while (last_char != EOF && last_char != '\n' && last_char != '\r');

            if (last_char != EOF) {
                return get_token();
            }

        }

        // if the file has concluded itself,  we are going to return that the token is the EOF. 
        if (last_char == EOF) {
            return tok_EOF;
        }

        int this_car = last_char;
        last_char = std::getchar();
        return this_car;
    }

    return -1;

}
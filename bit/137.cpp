/**
 * Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

/**
 * The code makes use of 2 variables.

ones - At any point of time, this variable holds XOR of all the elements which have
appeared "only" once.
twos - At any point of time, this variable holds XOR of all the elements which have
appeared "only" twice.

So if at any point time,

A new number appears - It gets XOR'd to the variable "ones".
A number gets repeated(appears twice) - It is removed from "ones" and XOR'd to the
variable "twos".
A number appears for the third time - It gets removed from both "ones" and "twos".
The final answer we want is the value present in "ones" - coz, it holds the unique element.

So if we explain how steps 1 to 3 happens in the code, we are done.
Before explaining above 3 steps, lets look at last three lines of the code,

common_bit_mask = ~(ones & twos)

ones & = common_bit_mask

twos & = common_bit_mask

All it does is, common 1's between "ones" and "twos" are converted to zero.

For simplicity, in all the below explanations - consider we have got only 4 elements in the array (one unique element and 3 repeated elements - in any order).
 */


class Solution {
    public:
    // Let us take the example of {3, 3, 2, 3} to understand this
        int singleNumber(vector<int>& A) {
            int n = A.size();
            int ones=0, twos =0;
            int common_bit_mask;
            for(int i=0; i<n;i++)
            {
                 /* The expression "one & arr[i]" gives the bits that are
               there in both 'ones' and new element from arr[].  We
               add these bits to 'twos' using bitwise OR
     
               Value of 'twos' will be set as 0, 3, 3 and 1 after 1st,
               2nd, 3rd and 4th iterations respectively */
               
                twos= twos|(ones&A[i]);
                /* XOR the new bits with previous 'ones' to get all bits
               appearing odd number of times
     
               Value of 'ones' will be set as 3, 0, 2 and 3 after 1st,
               2nd, 3rd and 4th iterations respectively */
                ones=ones^A[i];
                 /* The common bits are those bits which appear third time
               So these bits should not be there in both 'ones' and 'twos'.
               common_bit_mask contains all these bits as 0, so that the bits can 
               be removed from 'ones' and 'twos'   
     
               Value of 'common_bit_mask' will be set as 00, 00, 01 and 10
               after 1st, 2nd, 3rd and 4th iterations respectively */
                common_bit_mask= ~(ones&twos);
                /* Remove common bits (the bits that appear third time) from 'ones'
                 
               Value of 'ones' will be set as 3, 0, 0 and 2 after 1st,
               2nd, 3rd and 4th iterations respectively */
                ones &=common_bit_mask;
                /* Remove common bits (the bits that appear third time) from 'twos'
     
               Value of 'twos' will be set as 0, 3, 1 and 0 after 1st,
               2nd, 3rd and 4th itearations respectively */
                twos &=common_bit_mask;
            }
            return ones;
        }
    };
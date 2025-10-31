public class BinarySearchSquareRoot {

    public static int findSqrt(int x) {
        if (x < 0) {
            throw new IllegalArgumentException("Input must be a non-negative number.");
        }
        if (x == 0 || x == 1) {
            return x;
        }

        long start = 1;
        long end = x;
        int result = 0;

        while (start <= end) {
            long mid = start + (end - start) / 2;
            
            if (mid * mid == x) {
                return (int) mid;
            } else if (mid * mid < x) {
                result = (int) mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return result;
    }

    public static void main(String[] args) {
        // Main method for simple local testing:
        System.out.println("Integer Square Root of 16 is: " + findSqrt(16));
        System.out.println("Integer Square Root of 8 is: " + findSqrt(8));
        System.out.println("Integer Square Root of 100 is: " + findSqrt(100));
    }
}
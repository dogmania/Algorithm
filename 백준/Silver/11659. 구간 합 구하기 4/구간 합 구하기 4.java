import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader buffer = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer tokenizer = new StringTokenizer(buffer.readLine());
        int n = Integer.parseInt(tokenizer.nextToken());
        int count = Integer.parseInt(tokenizer.nextToken());

        int sum[] = new int[n + 1];
        tokenizer = new StringTokenizer(buffer.readLine());

        for (int i = 1; i < n + 1; i++) {
            sum[i] = sum[i - 1] + Integer.parseInt(tokenizer.nextToken());
        }

        for (int i = 0; i < count; i++) {
            tokenizer = new StringTokenizer(buffer.readLine());
            int start = Integer.parseInt(tokenizer.nextToken());
            int end = Integer.parseInt(tokenizer.nextToken());
            System.out.println(sum[end] - sum[start - 1]);
        }
    }
}
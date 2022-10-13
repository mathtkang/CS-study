public class ExamSample {
    void fn() {
        System.out.println("없음");
    }

    void fn(int i) {
        System.out.println(i);
    }

    void fn(int i, int j) {
        int k = i + j;
        System.out.println(k);
    }
}

public class Main {
    public static void main(String args[]) {
        ExamSample es = new ExamSample();
        es.fn(2, 3);
    }
}

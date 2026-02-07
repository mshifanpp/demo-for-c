import java.util.Scanner;

class CPU {
    double price;

    // Parameterized constructor for CPU
    CPU(double price) {
        this.price = price;
    }

    // Inner class (non-static)
    class Processor {
        int cores;
        String manufacturer;

        // Parameterized constructor
        Processor(int cores, String manufacturer) {
            this.cores = cores;
            this.manufacturer = manufacturer;
        }
    }

    // Static nested class
    static class RAM {
        int memory;
        String manufacturer;

        // Parameterized constructor
        RAM(int memory, String manufacturer) {
            this.memory = memory;
            this.manufacturer = manufacturer;
        }
    }
}

public class CPUMAIN {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // CPU input
        System.out.print("Enter CPU price: ");
        double price = sc.nextDouble();

        CPU cpuObj = new CPU(price);

        // Processor input
        System.out.print("Enter number of cores: ");
        int cores = sc.nextInt();
        sc.nextLine(); // consume newline

        System.out.print("Enter processor manufacturer: ");
        String procMf = sc.nextLine();

        CPU.Processor p = cpuObj.new Processor(cores, procMf);

        // RAM input
        System.out.print("Enter RAM size (GB): ");
        int memory = sc.nextInt();
        sc.nextLine(); // consume newline

        System.out.print("Enter RAM manufacturer: ");
        String ramMf = sc.nextLine();

        CPU.RAM r = new CPU.RAM(memory, ramMf);

        // Output
        System.out.println("\n--- CPU DETAILS ---");
        System.out.println("CPU Price: " + cpuObj.price);
        System.out.println("Processor Cores: " + p.cores);
        System.out.println("Processor Manufacturer: " + p.manufacturer);
        System.out.println("RAM Memory: " + r.memory + " GB");
        System.out.println("RAM Manufacturer: " + r.manufacturer);
    }
}


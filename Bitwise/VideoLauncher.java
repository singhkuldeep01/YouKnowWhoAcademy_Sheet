import java.util.ArrayList;
import java.util.Scanner;

// Video class to represent individual video items
class Video { 
    private String title; 
    private double userRating; 
    private int totalRatingCount; 
    private boolean isAvailable; 

    public Video(String title) { 
        this.title = title; 
        this.userRating = 0;
        this.totalRatingCount = 0;
        this.isAvailable = true;
    }

    public String getTitle() {
        return title;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void setCheckedOut() {
        isAvailable = false;
    }

    public void setReturned() {
        isAvailable = true;
    }

    public void addRating(int rating) {
        userRating = (userRating * totalRatingCount + rating) / (++totalRatingCount);
    }

    public double getUserRating() {
        return userRating;
    }
}

// VideoStore class to manage a collection of videos
class VideoStore {
    private ArrayList<Video> inventory;

    public VideoStore() {
        inventory = new ArrayList<>();
    }

    public void addVideo(String title) {
        inventory.add(new Video(title));
        System.out.println("Video \"" + title + "\" added to the store.");
    }

    public void listInventory() {
        if (inventory.isEmpty()) {
            System.out.println("No videos in inventory.");
            return;
        }
        for (Video video : inventory) {
            System.out.println("Title: " + video.getTitle() + 
                               ", Available: " + video.isAvailable() + 
                               ", Rating: " + video.getUserRating());
        }
    }

    public boolean rentVideo(String title) {
        for (Video video : inventory) {
            if (video.getTitle().equalsIgnoreCase(title) && video.isAvailable()) {
                video.setCheckedOut();
                System.out.println("Video \"" + title + "\" has been rented.");
                return true;
            }
        }
        System.out.println("Video \"" + title + "\" is not available.");
        return false;
    }

    public boolean returnVideo(String title) {
        for (Video video : inventory) {
            if (video.getTitle().equalsIgnoreCase(title) && !video.isAvailable()) {
                video.setReturned();
                System.out.println("Video \"" + title + "\" has been returned.");
                return true;
            }
        }
        System.out.println("Video \"" + title + "\" is not rented.");
        return false;
    }

    public boolean rateVideo(String title, int rating) {
        for (Video video : inventory) {
            if (video.getTitle().equalsIgnoreCase(title)) {
                video.addRating(rating);
                System.out.println("Rating added to video \"" + title + "\".");
                return true;
            }
        }
        System.out.println("Video \"" + title + "\" not found.");
        return false;
    }
}

// Main class to interact with the video store
public class VideoLauncher {
    public static void main(String[] args) {
        VideoStore store = new VideoStore();
        Scanner sc = new Scanner(System.in);

        while (true) {
            System.out.println("1. Add Video");
            System.out.println("2. List Inventory");
            System.out.println("3. Rent a Video");
            System.out.println("4. Return a Video");
            System.out.println("5. Give a Rating to a Video");
            System.out.println("6. Exit");
            System.out.print("Enter your choice: ");
            int choice = sc.nextInt();
            sc.nextLine(); // Consume newline character

            switch (choice) {
                case 1:
                    System.out.print("Enter video name: ");
                    String title = sc.nextLine();
                    store.addVideo(title);
                    break;

                case 2:
                    System.out.println("Inventory List:");
                    store.listInventory();
                    break;

                case 3:
                    System.out.print("Enter video name to rent: ");
                    title = sc.nextLine();
                    store.rentVideo(title);
                    break;

                case 4:
                    System.out.print("Enter video name to return: ");
                    title = sc.nextLine();
                    store.returnVideo(title);
                    break;

                case 5:
                    System.out.print("Enter video name to rate: ");
                    title = sc.nextLine();
                    System.out.print("Enter rating (1 to 5): ");
                    int rating = sc.nextInt();
                    sc.nextLine(); // Consume newline character
                    if (rating >= 1 && rating <= 5) {
                        store.rateVideo(title, rating);
                    } else {
                        System.out.println("Invalid rating. Please enter a value between 1 and 5.");
                    }
                    break;

                case 6:
                    System.out.println("Exiting... Goodbye!");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice. Please try again.");
                    break;
            }
    }
    }
}

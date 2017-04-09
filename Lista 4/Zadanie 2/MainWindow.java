import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.io.BufferedReader;
import java.io.IOException;

public class MainWindow extends Frame {
    private TextField rowField;
    private TextField elementField;
    private Button submitButton;
    private Label rowDescription;
    private Label elementDescription;
    private Label answer;
    private Panel rowPanel;
    private Panel elementPanel;

    public MainWindow() {
        super("Pascal's Triangle");

        rowField = new TextField();
        elementField = new TextField();
        submitButton = new Button("Generate coefficient");
        rowDescription = new Label("Enter row");
        elementDescription = new Label("Enter number of element in row");
        rowPanel = new Panel();
        elementPanel = new Panel();
        answer = new Label();

        rowPanel.add(rowDescription);
        rowPanel.add(rowField);
        elementPanel.add(elementDescription);
        elementPanel.add(elementField);

        try {
            Process compiler = Runtime.getRuntime().exec("g++ -o RowOfPascalTriangle RowOfPascalTriangle.cpp -std=c++11");
        }
        catch(IOException ex) {}

        submitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    int rowNumber = Integer.parseInt(rowField.getText());
                    int elementNumber = Integer.parseInt(elementField.getText());
                    Process process = Runtime.getRuntime().exec("./RowOfPascalTriangle " + rowNumber + " " + elementNumber);

                    BufferedReader inputReader = new BufferedReader(new InputStreamReader(process.getInputStream()));
                    BufferedReader errorReader = new BufferedReader(new InputStreamReader(process.getErrorStream()));
                    
                    String line;
                    if((line = errorReader.readLine()) != null) {
                        answer.setText(line);
                        answer.setAlignment(Label.CENTER);
                        answer.setForeground(Color.RED);
                        answer.getParent().revalidate();
                    }
                    else {
                        answer.setText(inputReader.readLine());
                        answer.setAlignment(Label.CENTER);
                        answer.setForeground(Color.BLACK);
                        answer.getParent().revalidate();
                    }
                }
                catch(IOException | NumberFormatException ex) {
                    answer.setText("Argument is not correct!");
                    answer.setAlignment(Label.CENTER);
                    answer.setForeground(Color.RED);
                    answer.getParent().revalidate();
                }
            }
        });

        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        this.setLayout(new GridLayout(4, 1));
        this.add(rowPanel);
        this.add(elementPanel);
        this.add(submitButton);
        this.add(answer);
        this.pack();
        this.setVisible(true);
    }
}
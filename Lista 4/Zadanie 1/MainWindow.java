import java.awt.*;
import java.awt.event.*;

public class MainWindow extends Frame {
    private Panel elementsPanel;
    private Label description;
    private TextField textField;
    private Button button;
    private Panel rowsPanel;
    private Label[] labels;
    private int numberOfRows;
    private ScrollPane sp;

    public MainWindow() {
        super("Pascal's Triangle Generator");

        elementsPanel = new Panel();
        description = new Label("Write a size of tringle");
        textField = new TextField();
        button = new Button("Generate Pascal's Triangle");
        rowsPanel = new Panel();
        sp = new ScrollPane();

        elementsPanel.add(description);
        elementsPanel.add(textField);
        elementsPanel.add(button);

        sp.add(rowsPanel);


        textField.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) {
                if(e.getKeyCode() == KeyEvent.VK_ENTER) {
                    button.getActionListeners()[0].actionPerformed(new ActionEvent(new Object(), 0, ""));
                }
                super.keyPressed(e);
            }
        });

        button.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                try {
                    numberOfRows = Integer.parseInt(textField.getText());
                    generatePascalTriangle();
                }
                catch(NegativeArraySizeException | IllegalArgumentException ex) {
                    rowsPanel.removeAll();
                    rowsPanel.setLayout(new GridLayout(1, 1));
                    labels = new Label[1];
                    labels[0] = new Label("Entered value is not correct.");
                    labels[0].setAlignment(Label.CENTER);
                    labels[0].setForeground(Color.RED);
                    rowsPanel.add(labels[0]);
                    rowsPanel.getParent().revalidate();
                }
            }
        });

        this.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });

        this.setBounds(200, 200, 800, 600);
        this.setLayout(new BorderLayout());
        this.add(elementsPanel, BorderLayout.NORTH);
        this.add(sp, BorderLayout.CENTER);

        this.setVisible(true);
    }

    private void generatePascalTriangle() {
        rowsPanel.removeAll();
        rowsPanel.setLayout(new GridLayout(numberOfRows+1, 1));

        labels = new Label[numberOfRows+1];
        for(int i = 0; i <= numberOfRows; i++) {
            RowOfPascalTriangle row = new RowOfPascalTriangle(i);
            String rowString = "";
            for(int j = 0; j <= i; j++) {
                rowString = rowString + row.coefficient(j) + " ";
            }
            labels[i] = new Label(rowString);
            labels[i].setAlignment(Label.CENTER);
            labels[i].setFont(new Font("Times New Roman", Font.BOLD, 15));
            rowsPanel.add(labels[i]);
        }
        this.revalidate();
    }

}
package com.donkeykongjr.ui;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import com.donkeykongjr.logic.Game;

public class MainWindowsJavaController {

    private Game game = Game.getInstance();

    @FXML
    private Button exitButton;

    @FXML
    private TextField Points;

    @FXML
    private Label addFruit;

    @FXML
    private TextField NPosFruit;

    @FXML
    private TextField MposEnemy;

    @FXML
    private Button redEnemy;

    @FXML
    private TextField MPosFruit;

    @FXML
    private Button fruitButton;

    @FXML
    private TextField NPosEnemy;

    @FXML
    private Button blueEnemy;

    @FXML
    void addFruit() {
        String posicionI = MPosFruit.getText();
        String posicionJ = NPosFruit.getText();
        Integer i = Integer.valueOf(posicionI);
        Integer j = Integer.valueOf(posicionJ);
        game.addFruitToMatrix(i, j);

    }

    @FXML
    void addRedEnemy() {
        String posicionI = MposEnemy.getText();
        String posicionJ = NPosEnemy.getText();
        Integer i = Integer.valueOf(posicionI);
        Integer j = Integer.valueOf(posicionJ);
        game.addRedEnemyToMatrix(i, j);
    }

    @FXML
    void addBlueEnemy() {
        System.out.println("f");
        String posicionI = MposEnemy.getText();
        String posicionJ = NPosEnemy.getText();
        Integer i = Integer.parseInt(posicionI);
        Integer j = Integer.parseInt(posicionJ);
        game.addBlueEnemyToMatrix(i, j);
    }

    @FXML
    void quitGame() {

    }

}

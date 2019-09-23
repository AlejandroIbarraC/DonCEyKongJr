package com.donkeykongjr.ui;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import com.donkeykongjr.logic.Game;

public class MainWindowsJavaController {

    private Game game = Game.getInstance();

    @FXML
    private Button addEnemyButton;

    @FXML
    private TextField addEnemyRowEntry;

    @FXML
    private TextField addEnemyColumnEntry;

    @FXML
    private TextField addEnemyGameEntry;

    @FXML
    private TextField addEnemyTypeEntry;

    @FXML
    private Button addFruitButton;

    @FXML
    private TextField addFruitRowEntry;

    @FXML
    private TextField addFruitColumnEntry;

    @FXML
    private TextField addFruitGameEntry;

    @FXML
    private TextField addFruitPointsEntry;

    @FXML
    private TextField addFruitTypeEntry;

    @FXML
    private Label connectingToInfoLabel;

    @FXML
    private Label addEnemyErrorLabel;

    @FXML
    private Button exitButton;

    @FXML
    private Button removeFruitButton;

    @FXML
    private TextField removeFruitGameEntry;

    @FXML
    private TextField removeFruitRowEntry;

    @FXML
    private TextField removeFruitColumnEntry;

    @FXML
    void addFruit() {
        String row = addFruitRowEntry.getText();
        String column = addFruitColumnEntry.getText();
        String type = addFruitTypeEntry.getText();
        String gameNumber = addFruitGameEntry.getText();
        try {
            Integer i = Integer.valueOf(row);
            Integer j = Integer.valueOf(column);
            if (type.equals("Banana") || type.equals("banana")) {
                game.ddFruitToMatrixBanana(i, j);}
            else if (type.equals("Apple") || type.equals("apple")) {
                game.ddFruitToMatrixApple(i, j);}
            else if (type.equals("Mango") || type.equals("mango")) {
                game.ddFruitToMatrixMango(i, j);}
            else {
                addFruitErrorLabel.setText("Wrong fruit type to add");
         catch (Exception e){
            System.out.println("\tError!\n\t¡Please insert numbers!");
        }
    }

    @FXML
    void addEnemy() {
        String row = addEnemyRowEntry.getText();
        String column = addEnemyColumnEntry.getText();
        String type = addEnemyTypeEntry.getText();
        String gameNumber = addEnemyGameEntry.getText();
        try {
            Integer i = Integer.valueOf(row);
            Integer j = Integer.valueOf(column);
            if (type.equals("Red") || type.equals("red")) {
                game.addRedEnemyToMatrix(i, j);
            } else if (type.equals("Blue") || type.equals("blue")) {
                game.addBlueEnemyToMatrix(i, j);
            } else {
                addEnemyErrorLabel.setText("Wrong enemy type to add");
            }
        } catch (Exception e) {
            System.out.println("\tError!\n\t¡Please insert numbers!");
        }
    }

    @FXML
    void connect1() {

    }

    @FXML
    void connect2() {

    }

    @FXML
    void removeFruitFromMatrixVyne() {
        String row = removeFruitRowEntry.getText();
        String column = removeFruitColumnEntry.getText();
        String gameNumber = removeFruitGameEntry.getText();
        try {
            Integer i = Integer.valueOf(row);
            Integer j = Integer.valueOf(column);
            System.out.println("Fruit removed from game Matrix!!");
            game.removeFruitFromVyne(i, j);
        } catch (Exception e){
            System.out.println("\tError!\n\t¡Please insert numbers!");
        }


    }

    void removeFruitFromMatrixField() {
        String row = removeFruitRowEntry.getText();
        String column = removeFruitColumnEntry.getText();
        String gameNumber = removeFruitGameEntry.getText();
        try {
            Integer i = Integer.valueOf(row);
            Integer j = Integer.valueOf(column);
            System.out.println("Fruit removed from game Matrix!!");
            game.removeFruitFromField(i, j);
        } catch (Exception e){
            System.out.println("\tError!\n\t¡Please insert numbers!");
        }


    }

    @FXML
    void startGame1() {

    }

    @FXML
    void startGame2() {

    }

    @FXML
    void quitGame() {
        Platform.exit();
    }

}

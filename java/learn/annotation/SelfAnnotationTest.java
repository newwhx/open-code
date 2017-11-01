import javax.swing.*;
import java.awt.event.*;

public class SelfAnnotationTest {
		private JFrame mainWin = new JFrame("使用注解绑定事件监听");

		@ActionListenerAnnotation(listener=OkListener.class)
		private JButton ok = new JButton("确定");

		@ActionListenerAnnotation(listener=CancelListener.class)
		private JButton cancel = new JButton("取消");

		private void init() {
				JPanel jp = new JPanel();
				jp.add(ok);
				jp.add(cancel);
				mainWin.add(jp);
				ActionListenerInstaller.processAnnotations(this);
				mainWin.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				mainWin.pack();
				mainWin.setVisible(true);
		}
		
		public static void main(String[] args) {
				new SelfAnnotationTest().init();
		}
}

class OkListener implements ActionListener {
		public void actionPerformed(ActionEvent evt){
				JOptionPane.showMessageDialog(null, "单击了确认按钮");
		}
}


class CancelListener implements ActionListener {
		public void actionPerformed(ActionEvent evt){
				JOptionPane.showMessageDialog(null, "单击了取消按钮");
		}
}


